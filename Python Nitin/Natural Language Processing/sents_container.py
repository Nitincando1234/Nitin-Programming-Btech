import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp("A Severe storm hit the beach. It started to rain.")
for sentence in doc.sents:
    a = [sentence[i] for i in range(len(sentence))]
print(a)
for i in range(len(doc)):
    b = [doc[i] for i in range(len(doc))]
print(b)
for i, sentence in enumerate(doc.sents):
    if i == 1 and sentence[0].pos_ == "PRON":
        print("Second Sentence starts with a pronoun")
counter = 0
for sentence in doc.sents:
    if sentence[len(sentence) - 2].pos_ == "VERB":     # -1 for 0 indexing and -1 for the .
        counter += 1 
print(counter)
