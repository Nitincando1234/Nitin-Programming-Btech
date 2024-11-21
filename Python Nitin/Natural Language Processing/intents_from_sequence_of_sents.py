import spacy
nlp = spacy.load("en_core_web_md")
doc = nlp(u"I have finished my pizza. I want another one.")
verbList = [('order','want','give','make'),('show','find')]
dobjList = [('pizza','pie','pizzaz'),('cola','soda')]
substitutes = ('one','it','same','more')
intent = {"verb": "", "dobj": ""}
for token in doc:
    if token.dep_ == "dobj":
        verbSyns = [item for item in verbList if token.head.text in item]
        dobjSyns = [item for item in dobjList if token.text in item]
        substitute = [item for item in substitutes if token.text in item]
        if verbSyns != [] and (dobjSyns != [] or substitute != []):
            intent["verb"] = verbSyns[0][0]
        if dobjSyns != []: intent["dobj"] = dobjSyns[0][0]
print(intent["verb"] + intent["dobj"].capitalize())
