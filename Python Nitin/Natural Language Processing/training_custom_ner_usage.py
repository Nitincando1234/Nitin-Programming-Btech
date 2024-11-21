import spacy
nlp = spacy.load("en_core_web_sm", disable = ["ner"])
ner = spacy.pipeline.EntityRecognizer(nlp.vocab, nlp)
ner.from_disk("./")
nlp.add_pipe(ner, "Custom_NER")
doc = nlp(u"Could you pick me up at Solnce?")
for token in doc:
    print(token.text, token.ent_type)