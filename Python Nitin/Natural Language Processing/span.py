import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"The Golden Gate Bridge is an ionic landmark in San Francisco.")

span = doc[1: 4]
lemma = span.text
with doc.retokenize() as retokenizer:
    retokenizer.merge(span, attrs = {"LEMMA": lemma})
