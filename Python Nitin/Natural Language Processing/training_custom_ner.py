import spacy
## General Structure of the Training Examples
# train_exes = [
#     ("Could you send a taxi to Solnce?",
#      {"entity": [(25, 32, "GPE")]}
#      ),
#      ("Is there a flat rate to the airport from Solnce?",
#       {"entity": [(41, 48, "GPE")]}
#       ),
#        ("How long is the wait for a taxi right now?",
#          {"entities": []
#     })
# ]
## Can also include doc but I am using the file method
nlp = spacy.load("en_core_web_lg")
# file = open("message.txt", "r")
# contents_file = file.read()
# doc = nlp(contents_file)
doc = nlp(u'Could you send a taxi to Solnce? I need to get to Google. Could you send a taxi an hour later?')
districts = ['Solnce', 'Greenwal', 'Downtown']
train_exs = []

for sent in doc.sents:
    entities = []
    entity = ()
    for token in sent:
        if token.ent_type != 0:
            start = token.idx - sent.start_char
            print(token.text)
            if token.text in districts:
                entity = (start, start + len(token), "GPE")
            else:
                if token.ent_type_ == "TIME": continue
                entity = (start, start + len(token), token.ent_type_ )
            entities.append(entity)
    tpl = (sent.text, {"entities": entities})
    train_exs.append(tpl)
print(train_exs)