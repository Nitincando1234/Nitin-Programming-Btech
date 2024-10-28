import spacy 
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"How to feed a cat !")
phrase = "failed !"
for token in reversed(doc):
    if token.dep_ == "dobj" and (token.pos_ == "NOUN" or token.pos_ == "PROPN"):
        phrase = token.head.lemma_ + "ing " + token.text
        break
print(phrase)
