import spacy
nlp = spacy.load(r"en_core_web_lg")
token = nlp(u"fruits")[0]
doc = nlp(u"I want to buy this beautiful book at the end of the week. Sales of citrus have increased over the last year. How much do you know about this type of tree?")
for sentence in doc.sents:
    print(sentence.text)
    print("similarity to ", token.text, " is ", token.similarity(sentence))