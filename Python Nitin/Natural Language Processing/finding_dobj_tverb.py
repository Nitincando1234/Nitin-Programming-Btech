import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"Show me best hotel in Berlin.")
for token in doc:
    if token.dep_ == "dobj": print(token.head.text + " " + token.text.capitalize())