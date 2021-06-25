import imaplib

mail = imaplib.IMAP4_SSL("imap.gmail.com")
mail.login("lost.func@gmail.com", "rgzekyhzyfryrdbe")
mail.select("inbox") # send to inbox

code, response = mail.search(None, "UNSEEN")
#     response is usually a list of all unread subjects in the mail

unreadMessage = response[0].split()[0] # read first subject

print (unreadMessage)
# if (len(unreadMessage) > 0):
    # switch light status
