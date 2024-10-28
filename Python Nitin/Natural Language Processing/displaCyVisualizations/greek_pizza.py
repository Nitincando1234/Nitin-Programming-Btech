import spacy
from spacy import displacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want a greek pizza")
displacy.serve(doc, style = "dep")
