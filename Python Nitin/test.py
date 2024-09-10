import pyodbc
connection_string = ("DRIVER={MySQL ODBC 9.0 Unicode Driver};"
                     "SERVER=localhost;"
                     "DATABASE=test;"
                     "UID=root;"
                     "PWD=123456;")
connection = pyodbc.connect(connection_string)
cursor_obj = connection.cursor()
cursor_obj.execute("SELECT * FROM students;")
readed = cursor_obj.fetchall()
print(readed)