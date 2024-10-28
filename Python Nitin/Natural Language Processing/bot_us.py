import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"Tell me about the color of the sky.")
phrase = "failed !"
for token in doc:
    if token.dep_ == "pobj" and (token.pos_ == "NOUN" or token.pos_ == "PROPN"):
        phrase = (" ".join([t.text for t in token.lefts]) + " " + token.text)
        if bool([prep for prep in token.rights if prep.dep_ == "prep"]):
            prep = list(token.rights)[0]
            pobj = list(prep.children)[0]
            phrase = phrase + " " + prep.text + " " + pobj.text
        break
print(phrase)