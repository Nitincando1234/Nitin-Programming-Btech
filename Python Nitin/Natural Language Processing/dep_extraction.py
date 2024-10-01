import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I have flown to LA. I am now flying to San Francisco.")

for token in doc:
    print(token.text, token.pos_, token.dep_)

for sentence in doc.sents:
    print([w.text for w in sentence if w.dep_ == "pobj" or w.dep_ == "ROOT"])