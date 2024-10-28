from spacy import util
print(util.get_package_path("en_core_web_sm"))
lang = "en"
pipeline = ["ner", "tagger", "parser"]
model_data_path = r"C:\Users\LENOVO\AppData\Local\Programs\Python\Python312\Lib\site-packages\en_core_web_sm3.7.1"
lang_cls = util.get_lang_class(lang)
nlp = lang_cls()

for name in pipeline:
    nlp.add_pipe(name) 
nlp.from_disk(model_data_path)