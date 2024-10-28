import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp("The Film earned $217 million in 2017.")
phrase = ""

for token in doc:
    if token.tag_ == "$":
        phrase = token.text
        i = token.i + 1
        while doc[i + 1].tag_ == "CD":
            phrase += doc[i].text + " " + "million"
            i += 1
        break

print(phrase)
