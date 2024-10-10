import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"The product sales hit a new record in the first quarter, with 18.6 million units sold.")
phrase = ""
for token in doc: 
    if token.pos_ == "NUM":
        while True:
            phrase = phrase + " " + token.text
            # print(token.text)
            token = token.head
            # print(token.text)
            if token not in token.head.lefts:
                phrase = phrase + " " + token.text
                break
        while True:
            token = doc[token.i].head
            if token.pos_ != "ADP":
                phrase = token.text + " " + phrase
            if token.dep_ == "ROOT": 
                break
        for tok in token.lefts:
            if tok.dep_ == "nsubj":
                phrase = " ".join([tok.text for tok in tok.lefts]) + " " + tok.text + " " + phrase
                break
        break
print(phrase.strip())
