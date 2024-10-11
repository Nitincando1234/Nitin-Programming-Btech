import spacy
nlp = spacy.load("en_core_web_lg")
doc = nlp(u"Could you pick meup at a Solnce ?")
for ent in doc.ents:
    print(ent.text, ent.label_)