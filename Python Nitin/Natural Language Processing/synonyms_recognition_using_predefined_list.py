import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"I want a pizza.")
dobj, verb = "", ""
for token in doc:
    if token.dep_ == "dobj":
        dobj = token
        verb = token.head
verbSynList = [("order", "want", "give", "make"), ("show", "find")
]
dobjSynList = [("pizza", "pie", "dish"), ("cola", "soda")]
dobjSyn, verbSyn = "", ""
for item in dobjSynList:
    if dobj.text in item: dobjSyn = item[0]
for item in verbSynList:
    if verb.text in item: verbSyn = item[0]
print(verbSyn.capitalize() + " " + dobjSyn.capitalize())
