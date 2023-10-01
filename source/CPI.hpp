#ifndef CPI_HPP
#define CPI_HPP

#include <string>

namespace woXrooX{

	class CPI{
	public:
		static std::string absolute_path;
		static std::string file_name;

		static std::string bridge(const std::string& data){
			if(CPI::absolute_path.empty()) return "Ivalid path";
			if(CPI::file_name.empty()) return "Ivalid filename";

			// python3 source/CPI.py absolute_path file_name data
			const std::string prepared = "python3 source/CPI.py " +CPI::absolute_path+ " " +CPI::file_name+ " '" +data+ "'";
			char buffer[128];

			std::string response = "";

			FILE* pipe = popen(prepared.c_str(), "r");

			if(!pipe) return "Error!";

			try{
				while(fgets(buffer, sizeof(buffer), pipe) != NULL) response += buffer;
			}catch(...){
				pclose(pipe);
				return "Error!";
			}

			pclose(pipe);
			return response;
		}
	};

	std::string CPI::absolute_path;
	std::string CPI::file_name;
}

#endif
