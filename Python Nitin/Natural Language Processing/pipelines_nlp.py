import spacy
nlp = spacy.load("en_core_web_sm")
print(nlp.pipe_names)
nlp = spacy.load("en_core_web_sm", disable = ["parser"])
print(nlp.pipe_names)
print(nlp.meta["lang"] + "_" + nlp.meta["name"])
print(nlp.meta["lang"] + "_" + nlp.meta["name"] + nlp.meta["version"])