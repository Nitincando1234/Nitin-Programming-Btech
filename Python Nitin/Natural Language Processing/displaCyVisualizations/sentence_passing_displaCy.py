import spacy
from spacy import displacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want a greek pizza. It is exotic.")
sents = doc.sents
options = {"font": "tahoma", "compact": True}
displacy.serve(list(sents), style = "dep", options = options)