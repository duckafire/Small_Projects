function markdownCodeChunkToHtml(chunk, classPrefix, elementClasses, langContent, classesList){
	function error(arg, typ){ console.log("[CODE-CHUNK-PARSER] '" + arg + "' needs to be " + typ + "."); }
	function wasOmmited(arg){ return (arg == undefined || arg == null); }

	if(typeof chunk != "string"){
		error("chunk", "a string");
		return null;
	}

	if(!wasOmmited(classPrefix) && typeof classPrefix != "string"){
		error("classPrefix", "a string");
		return null;
	}

	if(!wasOmmited(elementClasses) && !Array.isArray(elementClasses)){
		error("elementClasses", "a string array");
		return null;
	}

	if(!wasOmmited(langContent) && typeof langContent != "object"){
		error("langContent", "an object");
		return null;
	}

	if(!wasOmmited(classesList) && typeof classesList != "object"){
		error("classesList", "an object");
		return null;
	}


	function fillWithDefaultValues(arg, def){
		for(const key of Object.keys(def))
			if(wasOmmited(arg[key]))
				arg[key] = def[key];
	}

	const defaultClassesList = {
		ident: "ident",
		method: "method",
		constant: "constant",
		object: "object",
		keyword: "keyword",
		types: "type",
		value: "value",
		funct: "function",
		quotes: "string",
		number: "number",
		special: "special",
		nograph: undefined
	};

	const defaultLangContent = { keywords: [], types: [], values: [] }

	if(wasOmmited(classPrefix))
		classPrefix = "";

	if(wasOmmited(elementClasses))
		elementClasses = ["pre-chunk", "code-chunk"];
	else
		elementClasses = [elementClasses[0] || "pre-chunk", elementClasses[1] || "code-chunk"];

	if(wasOmmited(classesList))
		classesList = defaultClassesList;
	else
		fillWithDefaultValues(classesList, defaultClassesList);

	if(wasOmmited(langContent))
		langContent = defaultLangContent;
	else
		fillWithDefaultValues(langContent, defaultLangContent);


	function regex(str, exp){
		return (str.match(exp) != null);
	}

	const REGEX = {
		w: /^[a-z_A-Z]/,
		d: /^[0-9]/,
		s: /^[^\s]/,
		q: /^["']/,
		c: /^[A-Z_][A-Z_0-9]*$/,
		o: /^[A-Z]/, // class
		p: /^\./,
		split: /("[^"]*")|('[^']*')|([\d\w]+)|(\s+)/i,
	};

	const tokenList = chunk.split(REGEX.split).filter(item => item !== undefined && item !== "");

	class Element{
		content;
		clas;
		constructor(con, cla){
			this.content = con;
			this.clas = cla;
		}
	}

	let clas = "";
	let isMethod = false;
	let span = null;
	const elementList = [];

	const preElement  = document.createElement("pre");
	const codeElement = document.createElement("code");

	preElement.className  = elementClasses[0]
	codeElement.className = elementClasses[1];


	for(const token of tokenList){
		if(regex(token, REGEX.w)){
			if(isMethod){                                   clas = classesList.method;
			}else if(regex(token, REGEX.c)){                clas = classesList.constant;
			}else if(regex(token, REGEX.o)){                clas = classesList.object; // class
			}else if(langContent.keywords.includes(token)){ clas = classesList.keyword;
			}else if(langContent.types.includes(token)){    clas = classesList.type;
			}else if(langContent.values.includes(token)){   clas = classesList.value;
			}else{                                          clas = classesList.ident; }

		}else if(regex(token, REGEX.d)){ clas = classesList.number;
		}else if(regex(token, REGEX.q)){ clas = classesList.quotes;
		}else if(regex(token, REGEX.s)){
			if(token[0] == "(" && regex(elementList[ elementList.length - 1 ].content, REGEX.w))
				elementList[ elementList.length - 1 ].clas = classesList.funct;

			clas = classesList.special;
		}else{ clas = classesList.nograph;}

		isMethod = (regex(token, REGEX.p));

		elementList.push(new Element(token, clas));
	}

	
	for(const item of elementList){
		span = document.createElement("span");
		span.textContent = item.content;
		span.className   = classPrefix + item.clas;

		codeElement.appendChild(span);
	}

	preElement.appendChild(codeElement);
	return preElement;
}
