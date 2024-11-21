import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want a pizza and cola.")
for token in doc:
    if token.dep_ == "dobj":
        dobj = [token.text]
        conjs = [conj.text for conj in token.conjuncts]
        print(dobj + conjs)
        print(token.head)