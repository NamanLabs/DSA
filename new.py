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
def gen_random_string(length):
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str
def generate_customer_data(num_customers):
    data = []
    for i in range(num_customers):
        customer_id = i+1
        customer_name = gen_random_string(random.randint(5, 10))
        customer_age = random.randint(18, 60)
        # Generates mobile number 
        base = random.randint(700000000, 999999999)
        customer_mobile = str(base)
        customer_type = random.choice(["Action", "Comedy", "Drama", "Sci-Fi", "Romance"])
        customer_rating = round(random.uniform(1, 10), 1)
        data.append([customer_id, customer_name, customer_age, customer_mobile, customer_type, customer_rating])
    return data
# Generate data
num_customers = 50
data = generate_customer_data(num_customers)
df = pd.DataFrame(data, columns=['Customer ID', 'Customer Name', 'Age', 'Mobile No.', 'Preferred Type', 'Rating'])
# Save DataFrame to CSV 
df.to_csv('data.csv', index=False)
# Read DataFrame from CSV
df = pd.read_csv('data.csv')
# Creates list of Customer
customers = []
for _, row in df.iterrows():
    customer = Customer(row['Customer ID'], row['Customer Name'], row['Age'], row['Mobile No.'], row['Preferred Type'], row['Rating'])
    customers.append(customer)
# Display customers
for customer in customers:
    print(f"Customer ID: {customer.id}, Name: {customer.name}, Age: {customer.age}, Mobile: {customer.mobile}, Type: {customer.type}, Rating: {customer.rating}")