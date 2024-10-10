import spacy
from spacy.displacy import render
import pathlib
nlp = spacy.load("en_core_web_lg")
doc = nlp(u"In 2011 Google launched Google+ , it's forth foray in social networking.")
doc.user_data["title"] = "the example of entity recognization"
options = {"ents": ["ORG", "PRODUCT", "DATE"], "colors": {"PRODUCT": "orange", "DATE": "red"}}

html = render(doc, style = "ent", options = options, page = True)
output_path = pathlib.Path("displaCyVisualizations/entity_rec.html")
output_path.open("w", encoding = "utf-8").write(html)