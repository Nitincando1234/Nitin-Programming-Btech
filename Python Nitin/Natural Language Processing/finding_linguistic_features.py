import spacy
nlp = spacy.load("en_core_web_lg")
doc1 = nlp(u"We must overtake them.")
doc2 = nlp(u"You must specify this.")
for i in range(len(doc1)):
    if doc1[i].dep_ == doc2[i].dep_:
        print(doc1[i].text, doc2[i].text, doc1[i].dep_)