from bs4 import BeautifulSoup
import requests
import pandas as pd

url = "https://chennai.vit.ac.in/academics/schools/scse/faculty/"

# Create a dictionary
d = {'key': 'value'}

# Update the dictionary
d['new key'] = 'new value'

faculty_list = {}
faculty_number = 0
response = requests.get(url, verify=False)
data = response.text
html_source_code = BeautifulSoup(data, 'html.parser')
Faculty_block_html = html_source_code.find_all('div', {'class': 'item-content'})
for faculty in Faculty_block_html:
    name_tag = faculty.find('h3', {'class': 'item-title'})
    name = name_tag.text[0:] if name_tag else "N/A"  # To avoid none error
    Designation_tag = faculty.find('h4', {'class': 'small-text'})
    Designation = Designation_tag.text[0:] if Designation_tag else "N/A"  # To avoid none error
    faculty_number += 1
    faculty_list[faculty_number] = [name, Designation]

print("Total Faculties:", faculty_number)
final_list = pd.DataFrame.from_dict(faculty_list, orient='index', columns=['name', 'Designation'])

final_list.to_csv('faculty_list.csv')  # convert to CSV