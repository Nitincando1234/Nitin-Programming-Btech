import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I have flown to LA. I am now flying to Frisco.")

for token in doc:
    if token.ent_type != 0:     # mean it an entity
        print(token.text, token.ent_type_)