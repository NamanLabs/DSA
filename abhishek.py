import random
import string
import pandas as pd

# Step 1: Generate random salary data
def generate_salary():
    return round(random.uniform(1000, 50000), 2)

# Step 2: Generate random employee names from a 50-character string
def generate_employee_name(base_string, min_length=3, max_length=10):
    name_length = random.randint(min_length, max_length)
    return ''.join(random.choices(base_string, k=name_length))

# Step 3: Generate random age, mobile number, and employee ID
def generate_age():
    return random.randint(18, 65)

def generate_mobile_number():
    return "9" + ''.join(random.choices(string.digits, k=9))

def generate_employee_id():
    return random.randint(1000, 9999)

# Generate base string for names
base_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

# Generate random employee data
employees = []
for _ in range(50):  # Assuming we are creating data for 50 employees
    employee = {
        "Employee ID": generate_employee_id(),
        "Name": generate_employee_name(base_string),
        "Age": generate_age(),
        "Mobile Number": generate_mobile_number(),
        "Salary": generate_salary()
    }
    employees.append(employee)

# Step 4: Store data in a DataFrame and save to file
df = pd.DataFrame(employees)
df.to_csv("employee_data.csv", index=False)

# Step 5: Fetch data from the DataFrame and store in class objects
class Employee:
    def __init__(self, emp_id, name, age, mobile, salary):
        self.emp_id = emp_id
        self.name = name
        self.age = age
        self.mobile = mobile
        self.salary = salary

    def __repr__(self):
        return f"Employee(ID: {self.emp_id}, Name: {self.name}, Age: {self.age}, Mobile: {self.mobile}, Salary: {self.salary})"

employee_list = []
for _, row in df.iterrows():
    emp = Employee(row["Employee ID"], row["Name"], row["Age"], row["Mobile Number"], row["Salary"])
    employee_list.append(emp)

# Step 6: Find employees with salary greater than 15000
high_salary_employees = [emp for emp in employee_list if emp.salary > 15000]

# Display the results
print("Employees with salary greater than 15000:")
for emp in high_salary_employees:
    print(emp)
