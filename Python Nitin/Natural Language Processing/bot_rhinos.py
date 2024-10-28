import spacy
nlp = spacy.load("en_core_web_lg")
doc = nlp(u"What can you say about wild mountain goats?")
for token in doc:
    if token.dep_ == "pobj" and (token.pos_ == "NOUN" or token.pos_ == "PROPN"):
        phrase = (" ".join([t.text for t in token.lefts]) + " " + token.text)
        break
print(phrase)