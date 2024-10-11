import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want to place an order for a pizza.")
dobj, tverb = ("", "")
intentObj = ""
intentVerb = ""
for token in doc:
    dobj, tverb = (token, token.head)
    if token.dep_ == "obj":
        dobj = token
        tverb = token.head
    verbList = ["want", "like", "need", "order"]
    
    if tverb.text in verbList:
        intentVerb = tverb
    else:
        if tverb.head.dep_ == "ROOT":
            intentVerb = tverb
    objList = ["pizza", "cola"]

    if dobj.text in objList:
        intentObj = dobj
    else:
        for child in dobj.children:
            if child.dep_ == "prep":
                # print(list(child.children)[0].text)
                intentObj = list(child.children)[0]
                break
            else:
                if child.dep_ == "compound":
                    # print(child)
                    intentObj = child
                    break
print(intentVerb.text + " " + intentObj.text.capitalize())