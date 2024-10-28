import spacy
nlp = spacy.load('en_core_web_sm')
doc = nlp(u"This is grammer")
print([w.text for w in doc])
# Lemmatization
print([w.lemma_ for w in doc])