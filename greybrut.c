import_code("/lib/prototype.h");
import_code("/lib/string.h");
import_code("/lib/algo.h");

//Charset
c = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

//brute loop
brute = function(key,char,max)
	key.push(char[0]);  //empty
	for i in range(0,char.len -1)
		key[key.len-1] = char[i]
		perm = Algo.permute(key.join(""),[])[0];
		print(perm);
		if not perm.len <= max then break;
		brute([perm],char,max);
	end for
end function

for m in range(1,16)
	for i in range(0,c.len -1)
		brute([c[i]],c,m);
	end for
end for
