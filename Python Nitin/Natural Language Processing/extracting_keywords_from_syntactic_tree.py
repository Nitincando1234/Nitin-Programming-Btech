import spacy
nlp = spacy.load("en_core_web_lg")
def det_destination(doc):
    for i, token in enumerate(doc):
        if token.ent_type != 0 and token.ent_type_ == "GPE":     # GPE => for entity types of cities, countries etc
            while True:
                token = token.head
                if token.text == "to":
                    return doc[i].text
                if token == token.head: return "Unable to Determine"
    return "Unable to Determine"

doc = nlp(u"I am going to Berlin.")
print("It seems like user wants a ticket to: ", det_destination(doc))
# for token in doc:
#     print(token.text, "Head:", token.head, "Dep: ", token.dep_)