import json
import mysql
import mysql.connector
import spacy
nlp = spacy.load("en_core_web_lg")
doc = nlp("I want two Greek pizza.")
orderdict = {}
def wordto_int(numword):
    num = 0
    try:
        num = int(numword)
    except ValueError:
        words = ["zero", "one", "two", "three", "four", "five", "six", "seven",
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                "eight","nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
=======
     "eight","nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
     "eight","nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
     "eight","nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
        for i, word in enumerate(words):
            if word == numword: num = i
    return num
for token in doc:
    if token.dep_ == "dobj":
        dobj = token
        orderdict.update(product = dobj.lemma_)
        for child in dobj.lefts:
            if child.dep_ == "amod" or child.dep_ == "compound":
                orderdict.update(ptype = child.text)
            elif child.dep_ == "det":
                orderdict.update(qty = 1)
            elif child.dep_ == "nummod":
                orderdict.update(qty = wordto_int(child.text))
        break

# using mysql to implement in db
json_dict = json.dumps(orderdict)
try:
    connection = mysql.connector.connect(user = "root", password = "123456", host = "127.0.0.1", database = "mybot")
    cursor = connection.cursor()
    query = """
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            INSERT INTO orders (product, ptype, qty) 
            SELECT product, ptype, qty FROM 
            JSON_TABLE(
                %s,
                "$" COLUMNS( 
                    product VARCHAR(20) PATH "$.product" ERROR ON EMPTY,
                    ptype VARCHAR(25) PATH "$.ptype" ERROR ON EMPTY, 
                    qty INT PATH "$.qty" ERROR ON EMPTY
                )
            ) AS jt
            """
    cursor.execute(query, (json_dict, ))
=======
=======
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
            INSERT INTO orders(product, ptype, qty) INTO 
            SELECT (product, ptype, qty) FROM 
            JSON_TABLE(
            %s,
            "$" COLUMNS( 
            product VARCHAR(20) PATH "$.product" ERROR ON EMPTY,
            ptype VARCHAR(25) PATH "$.ptype"ERROR ON EMPTY, 
            qty INT PATH "$.qty" ERROR ON EMPTY
            )
            ) AS jt
            """
    cursor.execute(query, (json_dict))
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
    connection.commit()
except mysql.connector.Error as e:
    print(e.errno, ": {}".format(e.msg), " occured !")
finally:
    cursor.close()
    connection.close()