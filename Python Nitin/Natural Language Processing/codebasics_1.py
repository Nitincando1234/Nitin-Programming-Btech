import spacy
nlp = spacy.blank("en")
doc = nlp("Dr. Strange is Playing !")
for token in doc:
    print(token)