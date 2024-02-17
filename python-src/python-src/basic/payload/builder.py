class BasicBuilder(object):
    def __init__(self):
        pass

    def encode(self, name, group, msg):
        payload = f"{group},{name},{msg}"
        length = len(payload)
        encoded_payload = f"{length:04d},{payload}"
        print(f"Encoded payload: {encoded_payload}")
        return encoded_payload

    def decode(self, raw):
        # Print the raw payload before decoding
        print(f"Raw payload to decode: {raw}")
        # Split into 4 parts: length, group, name, msg
        parts = raw.split(",", 3)
        if len(parts) != 4:
            raise ValueError(f"message format error: {raw}")
        length, group, name, msg = parts
        if len(group + ',' + name + ',' + msg) != int(length):
            raise ValueError(f"message length mismatch: {raw}")
        return group, name, msg
