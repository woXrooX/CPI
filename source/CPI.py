import importlib.util
import sys

def import_file(absolute_path, file_name):
	try:
		spec = importlib.util.spec_from_file_location("module.name", absolute_path+'/'+file_name)
		imported_file = importlib.util.module_from_spec(spec)
		sys.modules["module.name"] = imported_file
		spec.loader.exec_module(imported_file)

		return imported_file.main

	except:
		return False

def main():
	if(len(sys.argv) != 4):
		print("Invalid argv")
		return

	absolute_path = sys.argv[1]
	file_name = sys.argv[2]
	data = sys.argv[3]

	f = import_file(absolute_path, file_name)
	if f != False: f()

	print(data)

	sys.stdout.buffer.write(b"Response from CPI.py\n")

if __name__ == "__main__": main()
