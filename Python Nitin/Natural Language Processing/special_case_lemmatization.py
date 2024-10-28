import spacy
from spacy.symbols import ORTH, LEMMA
nlp = spacy.load("en_core_web_sm")

special_case = [{ORTH: u"frisco"}]
nlp.tokenizer.add_special_case(u"frisco", special_case)
doc = nlp(u"I m flying to frisco")
print([w.text for w in doc])
for token in doc:
    if token.text == "frisco": token.lemma_ = "San Francisco"
print([w.lemma_ for w in doc])