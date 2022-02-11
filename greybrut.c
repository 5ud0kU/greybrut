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
		
		//Trying a first time no permute.
		md = md5(key.join(""));
		print("trying:" + md + " [" + key.join("") + "]");
		if md == "1769d06df18cb4c2b01931d7f83f3c9a" then exit("cracked:" + key.join("") + " in " + time);
		perm = Algo.permute(key.join(""),[])[0];
		
		//Trying a second time with permute.
		md = md5(perm);
		if md == "1769d06df18cb4c2b01931d7f83f3c9a" then exit("cracked:" + perm + " in " + time);
		print("trying:" + md + " [" + perm + "]");

		
		if not perm.len <= max then break;
		brute([perm],char,max);
	end for
end function

for m in range(4,4)
	for i in range(0,c.len -1)
		brute([c[i]],c,m);
	end for
end for
