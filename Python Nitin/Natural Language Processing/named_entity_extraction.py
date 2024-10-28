import spacy
nlp = spacy.load("en_core_web_lg")
doc1 = nlp(u"Google Search, often referred to as simply Google, is the most used search engine nowadays. It handles a huge number of searches each day")
doc2 = nlp(u"Microsoft Windows is a family of proprietary operating systems developed and sold by Microsoft. The company also produces a wide range of other software for desktops and servers.")
doc3 = nlp(u"Titicaca is a large, deep, mountain lake in the Andes. It is known as the highest navigable lake in the world.")

docs = [doc1, doc2, doc3]
spans = {}
for j, doc in enumerate(docs):
    doc_entity_span = [doc[i].text for i in range(len(doc)) if doc[i].ent_type != 0]
    doc_entity_span = " ".join(doc_entity_span)
    print(doc_entity_span)
