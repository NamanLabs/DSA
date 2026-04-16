import pandas as pd
import random
import string

class Customer:
    def __init__(self, id, name, age, mobile, type, rating):
        self.id = id
        self.name = name
        self.age = age
        self.mobile = mobile
        self.type = type
        self.rating = rating

def generate_random_string(length):
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str

def generate_customer_data(num_customers):
    data = []
    for i in range(num_customers):
        customer_id = i+1
        customer_name = generate_random_string(random.randint(5, 15))
        customer_age = random.randint(18, 60)
        customer_mobile = ''.join(random.choice(string.digits) for _ in range(10))
        customer_type = random.choice(["Action", "Comedy", "Drama", "Sci-Fi", "Romance"])
        customer_rating = round(random.uniform(1, 10), 1)
        data.append([customer_id, customer_name, customer_age, customer_mobile, customer_type, customer_rating])
    return data

# Generate sample data
num_customers = 50
data = generate_customer_data(num_customers)

# Create a DataFrame
df = pd.DataFrame(data, columns=['Customer ID', 'Customer Name', 'Age', 'Mobile No.', 'Preferred Type', 'Rating'])

# Save DataFrame to a CSV file
df.to_csv('customer_data.csv', index=False)

# Read the DataFrame from the CSV file
df = pd.read_csv('customer_data.csv')

# Create a list of Customer objects
customers = []
for _, row in df.iterrows():
    customer = Customer(row['Customer ID'], row['Customer Name'], row['Age'], row['Mobile No.'], row['Preferred Type'], row['Rating'])
    customers.append(customer)

# Display all customers
for customer in customers:
    print(f"Customer ID: {customer.id}, Name: {customer.name}, Age: {customer.age}, Mobile: {customer.mobile}, Type: {customer.type}, Rating: {customer.rating}")