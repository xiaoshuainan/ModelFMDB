
//
//  XSNSqliteTool.m
//  Common
//
//  Created by xsn on 2018/8/13.
//

#import "XSNSqliteTool.h"
#import <objc/runtime.h>

@implementation XSNSqliteTool

/**
 通过运行时获取当前对象的所有属性的名称，以数组的形式返回
 
 @param fieldNameModel 数据模型
 @return 返回数据模型的属性
 */
+ (NSArray *)allPropertyNamesFieldNameModel:(NSObject *)fieldNameModel{
    ///存储所有的属性名称
    NSMutableArray *allNames = [[NSMutableArray alloc] init];
    
    ///存储属性的个数
    unsigned int propertyCount = 0;
    
    ///通过运行时获取当前类的属性
    objc_property_t *propertys = class_copyPropertyList([fieldNameModel class], &propertyCount);
    
    //把属性放到数组中
    for (int i = 0; i < propertyCount; i ++) {
        //取出第一个属性
        objc_property_t property = propertys[i];
        
        const char * propertyName = property_getName(property);
        
        [allNames addObject:[NSString stringWithUTF8String:propertyName]];
    }
    
    ///释放
    free(propertys);
    
    return allNames;
}


/**
 Model转字典
 
 @param fieldNameModel 数据模型
 @return 转化后的字典
 */
+ (NSDictionary *)propertiesApsFieldNameModel:(NSObject *)fieldNameModel{
    
    NSMutableDictionary *props = [NSMutableDictionary dictionary];
    
    unsigned int outCount, i;
    
    objc_property_t *properties = class_copyPropertyList([fieldNameModel class], &outCount);
    
    for (i = 0; i<outCount; i++){
        //取出第一个属性
        objc_property_t property = properties[i];
        
        const char* char_f =property_getName(property);
        
        NSString *propertyName = [NSString stringWithUTF8String:char_f];
        
        id propertyValue = [fieldNameModel valueForKey:(NSString *)propertyName];
        
        if (propertyValue) [props setObject:propertyValue forKey:propertyName];
    }
    
    free(properties);
    
    return props;
}


/**
 生成随机数
 
 @param from 开始值
 @param to 结束值
 @return 生成的随机数
 */
+ (int)getRandomNumber:(int)from to:(int)to{
    int index = to - from;
    return (int)(from + (arc4random() % (index + 1)));
}

@end
