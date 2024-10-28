import spacy
nlp = spacy.load("en_core_web_lg")
def find_dep(doc):
    for i in range(len(doc) - 1):
        if doc[i].dep_ == "nsubj" and doc[i + 1].dep_ == "aux" and doc[i + 2].dep_ == "ROOT":
            for token in doc[i + 2].children:
                if token.dep_ == "dobj":
                    return True
        return False
doc = nlp(u"We can overtake them.")
if find_dep(doc):
    print("True")
else:
    print("False")