import spacy
from spacy import displacy
nlp = spacy.load("en_core_web_lg")
doc = nlp(u"In 2011 Google launched Google+ , it's forth foray in social networking.")
doc.user_data["title"] = "the example of entity recognization"
options = {"ents": ["ORG", "PRODUCT", "DATE"], "colors": {"PRODUCT": "orange", "DATE": "red"}}
displacy.serve(doc, style = "ent", options = options)