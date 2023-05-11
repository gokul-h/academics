import http.client

conn = http.client.HTTPSConnection("indianrailways.p.rapidapi.com")

headers = {
    'x-rapidapi-host': "indianrailways.p.rapidapi.com",
    'x-rapidapi-key': "68cee45e8emsh94c895bea1dd45fp17e64cjsn3fd1c44a73cb"
    }

conn.request("GET", "/findstations.php?station=delhi", headers=headers)

res = conn.getresponse()
data = res.read()

print(data.decode("utf-8"))