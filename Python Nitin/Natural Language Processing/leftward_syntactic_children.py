import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want a red Apple.")

print([w for w in doc[4].lefts])
print([w for w in doc[1].rights])
print([w for w in doc[4].children])     # All syntactic children