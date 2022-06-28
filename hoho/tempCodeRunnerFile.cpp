

        // fixCmd(cmd); /* Chỉnh sửa câu lệnh tránh các lỗi nhập cách khoảng */
        char **args =  separate_line(cmd); /* Chia câu lệnh */
            /**
             * VD: dir C:\Users\Admin .....
             * => args[0] : dir
             * => args[1] : C:\Users\Admin
             * .....
             **/