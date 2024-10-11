import spacy
nlp = spacy.load("en_core_web_md")
doc = nlp(u"I feel like eating a pie.")
for token in doc:
    if token.dep_ == "dobj":
        dobj = token
token = nlp(u"sweet")
print(dobj.similarity(token[0]))
if token[0].similarity(dobj) > 0.4:
    print("Would you like to look out at our menu ?")