import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I flown to LA. Now I am flying to Frisco.")

print([w.text for w in doc if w.tag_ == "VBG" or w.tag_ == "VB"])
print([w.text for w in doc if w.pos_ == "PROPN"])   # PROPN = proper noun

