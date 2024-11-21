from clarifai.rest import ClarifaiApp, Image
try:
    app = ClarifaiApp(api_key = "ae9c81dbb3644815aed858295a724f44")
    model = app.public_models.general_model
    image = Image(file_obj = open("grape.jpg", "rb"))
    response = model.predict([image])
    concepts = response["output"][0]["data"]["concepts"]
    for concept in concepts:
        print(concept["name"], concept["value"])
except Exception as e:
    print("Error: ", e)