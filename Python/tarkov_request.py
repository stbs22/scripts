import requests
from requests_html import HTML

r = requests.get("https://www.escapefromtarkov.com")
html = HTML(html="https://www.escapefromtarkov.com")

print(html.text)

