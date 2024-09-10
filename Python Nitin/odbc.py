import pyodbc as po
def display():
    query = "SELECT * FROM student;"
    cur.execute(query)
    for row in cur.fetchall():
        print(row)
connection_string = (
    "DRIVER={MySQL ODBC 9.0 Unicode Driver};"
    "SERVER=localhost;"
    "PORT=3306;"
    "DATABASE=students;"
    "UID=root;"
    "PWD=123456;"
)
conn = po.connect(connection_string)
#create cursor 
cur = conn.cursor()
display()
cur.execute("INSERT INTO STUDENT (Roll_no,StudentName) VALUES (?,?);",(6,'Aman'))
print("After inserting new row !")
display()
cur.commit()
conn.autocommit=True
conn.commit()
conn.close()


