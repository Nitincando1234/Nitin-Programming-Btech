<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
import random
import spacy
from spacy.util import minibatch
from spacy.util import compounding
from spacy.training import Example
=======
import spacy
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
import spacy
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
import spacy
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
other_pipes = [pipe for pipe in nlp.pipe_names if pipe != "ner"]
nlp.disable_pipes(*other_pipes)
# training the model

optimizer = nlp.create_optimizer()
for i in range(25):
    random.shuffle(train_exs)    
    max_batch = 3
    batch_size = compounding(2.0, max_batch, 1.001)
    batch = minibatch(train_exs, size = batch_size)
    for b in batch:
        examples = []
        for text, annotations in b:
            doc = nlp.make_doc(text)
            example = Example.from_dict(doc, annotations)
            examples.append(example)
    nlp.update(examples, sgd = optimizer)
ner = nlp.get_pipe("ner")
ner.to_disk("./")
print(train_exs)
=======
print(train_exs)
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
print(train_exs)
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
=======
print(train_exs)
>>>>>>> df1868658abf794e7c69642e20f06306b50f64d8
