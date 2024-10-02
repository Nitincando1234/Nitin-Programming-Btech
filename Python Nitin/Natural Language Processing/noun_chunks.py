import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"A noun chunk is a phrase that has a noun as it's head.")
for chunk in doc.noun_chunks:
    print(chunk, end = " ")
print()
# Alternative way
chunk = ""
for token in doc:
    if token.pos_ == "NOUN": chunk = ""
    for w in token.children:
        if w.pos_ == "DET" or w.pos_ == "ADJ":
            chunk = chunk + w.text + " "
    chunk = chunk + token.text
print(chunk)
    