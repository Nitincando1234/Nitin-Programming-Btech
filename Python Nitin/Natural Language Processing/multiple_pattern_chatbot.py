import spacy
nlp = spacy.load("en_core_web_sm")
def dep_pattern(doc):
    for i in range(len(doc) - 1):
        if doc[i].dep_ == "nsubj" and doc[i + 1].dep_ == "aux" and doc[i + 2].dep_ == "ROOT":
            for token in doc[i + 2].children:
                if token.dep_ == "dobj":
                    return True
    return False
def pos_pattern(doc):
    for token in doc:
        if token.dep_ == "nsubj" and token.tag_ != "PRP": return False
        elif token.dep_ == "ROOT" and token.tag_ != "VB": return False
        elif token.dep_ == "aux" and token.tag_ != "MD": return False
        elif token.dep_ == "dobj" and token.tag_ != "PRP": return False
    return True
def pron_pattern(doc):
    for token in doc:
        plural = ["we", "us", "they", "them"]
        if token.dep_ == "dobj" and token.tag_ == "PRP":
            if token.text in plural: return "plural"
            else: return "singular"
    return "not found"
def find_noun(sents, num):
    if num == "plural": taglist = ["NN", "NNP"]
    if num == "singular": taglist = ["NNS", "NNPS"]
    for sentence in reversed(sents):
        for token in sentence:
            if token.tag_ in taglist: return token.text
    return "Noun not found"
def gen_utternace(doc, noun):
    for i, token in enumerate(doc):
        if token.dep_ == "dobj" and token.tag_ == "PRP":
            sentence = doc[: i] + " " + noun + " " + doc[i + 1: len(doc) - 2] + " too. "
            return sentence
        return "Unable to generate utternace"
doc = nlp(u"'The symbols are clearly distinguishable. I can recognize them  promptly.")  
response = ""
noun = ""
for i, sent in enumerate(list(doc.sents)):
    if dep_pattern(sent) and pos_pattern(sent):
        
        noun = find_noun([sent[: i]], pron_pattern(sent))
        if noun != "Noun not found":
            response = gen_utternace(sent, noun)
            break
print(response)
# doc = nlp(u"We can Overtake them.")
# if dep_pattern(doc) and pos_pattern(doc): print("True, the position of direct object is: ", pron_pattern(doc))
# else: print("False")