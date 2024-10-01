import spacy
nlp = spacy.load("en_core_web_lg")
doc = nlp(u"I want a green apple")
print(doc.similarity(doc[3: 4]))
doc1 = nlp(u"I like red Oranges")
print(doc[3: 5].similarity(doc1[2: 4]))